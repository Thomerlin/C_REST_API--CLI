# Processo Seletivo 42 São Paulo: 42Labs 2ª edição
 
### O projeto consiste em desenvolver um REST API usando C e uma CLI (Command Line Interface).

## O que é necessário ter instalado para execução ?
<a href="https://curl.se/libcurl/c/libcurl-tutorial.html">LibCurl</a>

<a href="https://github.com/json-c/json-c">JSON-C</a>

<a href="https://insomnia.rest/download">Insomnia</a> ou Navegador

<a href="https://linuxhint.com/install-make-ubuntu/">Make</a> - Comando para executar Makefile

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
	/
	/coins
	/btc

## Como usar CLI?
`make` para compilar o projeto todo, `tanto a API quanto a CLI serão compiladas`.

`cd cli` para entrar na pasta.

`./cli logs` para ver todos os dados.

`./cli {caminho}` para ver dados específicos.

	Troque {caminho} por:
	/
	/coins
	/btc

