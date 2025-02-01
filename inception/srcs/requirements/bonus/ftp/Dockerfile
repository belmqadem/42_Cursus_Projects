FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y && \
    apt-get install -y vsftpd && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/vsftpd/empty /var/www/wordpress && \
    chmod 755 /var/run/vsftpd/empty

COPY conf/vsftpd.conf /etc/vsftpd.conf
COPY tools/ftp.sh /usr/local/bin/ftp.sh
RUN chmod +x /usr/local/bin/ftp.sh

CMD ["/usr/local/bin/ftp.sh"]