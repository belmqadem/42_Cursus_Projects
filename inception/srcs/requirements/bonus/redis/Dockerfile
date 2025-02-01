FROM debian:bullseye

RUN apt update -y && apt upgrade && \
    apt install -y redis-server && \
    apt clean && rm -rf /var/lib/apt/lists/*

COPY conf/redis.conf /etc/redis/redis.conf

CMD ["redis-server", "/etc/redis/redis.conf"]