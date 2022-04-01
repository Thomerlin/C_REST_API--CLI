# Processo Seletivo 42 São Paulo: 42Labs 2ª edição
 
### O projeto consiste em desenvolver uma REST API  e uma CLI (Command Line Interface) usando Linguagem C.

## O que é necessário ter instalado para execução ?
- <a href="https://curl.se/libcurl/c/libcurl-tutorial.html">LibCurl</a>

- <a href="https://github.com/json-c/json-c">JSON-C</a>

- <a href="https://insomnia.rest/download">Insomnia</a> ou Navegador

- <a href="https://linuxhint.com/install-make-ubuntu/">Make</a> - Comando para executar Makefile

## Como usar API?
`sudo make` para compilar o projeto todo, `tanto a API quanto a CLI serão compiladas`.

`cd api` para entrar na pasta.

`./api` para inicializar o server.

### Formato de Entrada e Retorno:
_A API recebe apenas método `GET HTTP` e retorna dados no formato `JSON`_

### Visualizando o retorno:
Use o <a href="https://insomnia.rest/download">Insomnia</a> ou o próprio `Navegador`.

Insira <a href="http://localhost:8000/">http://localhost:8000/</a> para ter acesso ao retorno `JSON`.

### Os caminhos posíveis são:
## /
```javascript
{
	"OK": "BATATA"
}
```

## /coins
```javascript
{
	"AUD": {
		"15m": 52258.43,
		"last": 52258.43,
		"buy": 52258.43,
		"sell": 52258.43,
		"symbol": "AUD"
	},
	"BRL": {
		"15m": 195443.1,
		"last": 195443.1,
		"buy": 195443.1,
		"sell": 195443.1,
		"symbol": "BRL"
	},
	"CAD": {
		"15m": 47857.49,
		"last": 47857.49,
		"buy": 47857.49,
		"sell": 47857.49,
		"symbol": "CAD"
	},

	... continua ...
```

## /btc
```javascript
{
"data": {
	"id": "bitcoin",
	"rank": "1",
	"symbol": "BTC",
	"name": "Bitcoin",
	"supply": "18969931.0000000000000000",
	"maxSupply": "21000000.0000000000000000",
	"marketCapUsd": "714140835337.4415581121037055",
	"volumeUsd24Hr": "10190356914.9112414043246031",
	"priceUsd": "37645.9374226211765405",
	"changePercent24Hr": "-3.1658909285388046",
	"vwap24Hr": "38581.2081211514545003",
	"explorer": "https:\/\/blockchain.info\/"
},
"timestamp": 1646009373651
} 
```

## Como usar CLI?
`sudo make` para compilar o projeto todo, `tanto a API quanto a CLI serão compiladas`.

`cd cli` para entrar na pasta.

`./cli logs` para ver todos os dados.
```bash
********************************************
|   REQUESTS  | HTTP Method  |   Path      |
|******************************************|
|     1      |     GET      |        /     |
|******************************************|
|     1      |     GET      |     /coins   |
|******************************************|
|     1      |     GET      |     /btc     |
|******************************************|
```


`./cli {caminho}` para ver dados específicos.

	Troque {caminho} por:
	/
	/coins
	/btc

### Comados make: "sudo só se necessário"
	make 
	make re
	make clean
	make fclean

## Tecnologias usadas

- <a href="https://mongoose.ws/documentation">Mogoose</a>

- <a href="https://curl.se/libcurl/c/libcurl-tutorial.html">LibCurl</a>

- <a href="https://github.com/json-c/json-c">JSON-C</a>

- <a href="https://en.wikipedia.org/wiki/ANSI_C">ANSI C</a>

- <a href="https://linuxhint.com/install-make-ubuntu/">Make</a>

- <a href="https://insomnia.rest/download">Insomnia</a>

- <a href="https://notion.so">Notion</a>
