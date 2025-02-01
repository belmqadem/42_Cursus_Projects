FROM debian:bullseye

RUN apt update -y && apt upgrade -y && \
    apt install -y nginx && \
    apt clean && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/static/
COPY site/ /var/www/static/

COPY conf/nginx.conf /etc/nginx/nginx.conf

CMD ["nginx", "-g", "daemon off;"]