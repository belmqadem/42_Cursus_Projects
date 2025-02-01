FROM debian:bullseye

RUN apt update -y && apt upgrade -y && \
    apt install -y wget gnupg2 apt-transport-https software-properties-common && \
    wget -q -O - https://packages.grafana.com/gpg.key | gpg --dearmor -o /usr/share/keyrings/grafana.gpg && \
    echo "deb [signed-by=/usr/share/keyrings/grafana.gpg] https://packages.grafana.com/oss/deb stable main" > /etc/apt/sources.list.d/grafana.list && \
    apt update -y && apt install -y grafana=10.0.0 && \
    apt clean && rm -rf /var/lib/apt/lists/*

WORKDIR /usr/share/grafana

CMD ["grafana-server"]