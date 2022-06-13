FROM node:13.7.0-alpine

COPY package.json .
COPY package-lock.json .
RUN npm install

WORKDIR /app
COPY . .

ENTRYPOINT [ "node", "index.js" ]  


