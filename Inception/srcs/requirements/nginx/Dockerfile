FROM	alpine:3.14

RUN		apk update --quiet && apk add --quiet --no-cache --update nginx && \
        apk add --quiet --no-cache --update openssl

RUN		mkdir /etc/nginx/ssl

RUN 	openssl req -x509 -nodes \
	    -out /etc/nginx/ssl/henkaoua.42.fr.crt \	
	    -keyout /etc/nginx/ssl/henkaoua.42.fr.key \
	    -subj "/C=CH/ST=VD/L=Lausanne/O=42/OU=42/CN=henkaoua.42.fr"

COPY	config/nginx.conf /etc/nginx/http.d/default.conf

EXPOSE	443

CMD	[ "nginx", "-g", "daemon off;" ]