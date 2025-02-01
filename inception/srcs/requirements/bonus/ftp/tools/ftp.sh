#!/bin/bash

useradd -d /var/www/wordpress "$FTP_USER" --no-create-home
echo "$FTP_USER:$FTP_PASS" | chpasswd
chown -R "$FTP_USER:$FTP_USER" /var/www/wordpress
exec /usr/sbin/vsftpd /etc/vsftpd.conf
