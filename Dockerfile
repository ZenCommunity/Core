FROM alpine:edge as build

WORKDIR /source

RUN apk add --update cmake make g++ git boost-dev

ARG APP_ENV="Debug"
ENV APP_ENV=$APP_ENV

ARG APP_PORT=5000
ENV APP_PORT=$APP_PORT

COPY source .

RUN ./build.sh

FROM alpine:edge as service

ARG APP_ENV="Debug"
ENV APP_ENV=$APP_ENV

ARG APP_PORT=5000
ENV APP_PORT=$APP_PORT

RUN apk add --update libstdc++

WORKDIR /app

COPY --from=build /source/Core /app
COPY --from=build /source/Test /app

RUN ./Test

COPY docker/entrypoint.sh .

ENTRYPOINT ["./entrypoint.sh"]
