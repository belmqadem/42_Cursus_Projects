FROM debian:bullseye

RUN apt update -y && apt upgrade -y && \
    apt install -y wget php php-mysql && \
    apt clean && rm -rf /var/lib/apt/lists/* && \
    mkdir -p /var/www/wordpress && \
    wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php -O /var/www/wordpress/index.php

WORKDIR /var/www/wordpress

CMD ["php", "-S", "0.0.0.0:8080"]