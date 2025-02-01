#!/bin/bash

mkdir -p /var/www/wordpress
cd /var/www/wordpress

if [ ! -f /usr/local/bin/wp ]; then
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
fi

if [ ! -f wp-config.php ]; then
    wp core download --allow-root

    mv wp-config-sample.php wp-config.php
    sed -i "s|database_name_here|${MYSQL_DATABASE}|" wp-config.php
    sed -i "s|username_here|${MYSQL_USER}|" wp-config.php
    sed -i "s|password_here|${MYSQL_PASSWORD}|" wp-config.php
    sed -i "s|localhost|mariadb|" wp-config.php

    sed -i "/^\/\* That's all, stop editing\! Happy publishing\. \*\//i \
define('WP_REDIS_HOST', 'redis');\n\
define('WP_REDIS_PORT', 6379);\n\
define('WP_REDIS_TIMEOUT', 1);\n\
define('WP_REDIS_READ_TIMEOUT', 1);\n\
define('WP_REDIS_DATABASE', 0);\n\
define('WP_REDIS_CLIENT', 'phpredis');\n\
define('WP_CACHE_KEY_SALT', '${DOMAIN_NAME}_');\n\
define('WP_CACHE', true);" wp-config.php
fi

echo "Waiting for database connection..."
sleep 10

if ! wp core is-installed --allow-root; then
    if [[ "${WP_ADMIN_USER}" =~ [Aa]dmin|[Aa]dministrator ]]; then
        echo "Error: Administrator username cannot contain 'admin', 'Admin', or 'administrator' ..."
        exit 1
    fi

    wp core install \
        --url="${DOMAIN_NAME}" \
        --title="${SITE_TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --skip-email \
        --allow-root

    wp user create \
        "${WP_USER}" "${WP_USER_EMAIL}" \
        --user_pass="${WP_USER_PASSWORD}" \
        --role=editor \
        --allow-root
fi

if ! wp theme is-installed twentytwentyfour --allow-root; then
    wp theme install twentytwentyfour --activate --allow-root
else
    wp theme activate twentytwentyfour --allow-root
fi

wp plugin install redis-cache --allow-root
wp plugin activate redis-cache --allow-root
wp plugin update --all --allow-root
wp redis enable --allow-root

mkdir -p /run/php

echo "Starting PHP-FPM..."
php-fpm7.4 -F
