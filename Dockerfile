FROM alpine:3.16.1 as build

WORKDIR /source

RUN apk add --update cmake make g++ git
ARG CORE_MODE="debug"
ENV CORE_MODE=$CORE_MODE
COPY source .
RUN ./build.sh

FROM alpine:3.16.1 as service

ENV CORE_MODE=$CORE_MODE
RUN apk add --update libstdc++
WORKDIR /app
COPY --from=build /source/Core /app
COPY --from=build /source/Test /app
RUN ./Test
COPY docker/entrypoint.sh .
ENTRYPOINT ["./entrypoint.sh"]
