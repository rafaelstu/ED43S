# AGENTS.md

Regras para agentes que trabalharem neste repositório de Estruturas de Dados.

## Princípio principal

Este repositório contém exercícios acadêmicos baseados em código fornecido em aula. O objetivo é **adaptar a base existente**, não reescrevê-la.

Antes de alterar qualquer arquivo, leia o código atual e identifique a menor mudança necessária para atender ao pedido.

## Regras obrigatórias

1. **Preserve a base original.**
   - Mantenha a estrutura, os nomes, os tipos e o nível de código já existentes.
   - Não troque a implementação por uma versão "melhor", mais moderna ou mais abstrata.
   - Não faça refatorações, reorganizações ou melhorias que não foram pedidas.

2. **Faça apenas o que foi solicitado.**
   - Altere somente os arquivos, funções, cases e trechos necessários.
   - Não modifique menus, numeração, mensagens ou comportamentos existentes além do pedido.
   - Não adicione opções, funções ou funcionalidades extras por conta própria.

3. **Não crie funções auxiliares na `main`.**
   - A `main` deve continuar concentrando o menu e o `switch`.
   - A lógica das operações deve ficar no TAD (`.c`/`.h`), seguindo o padrão do projeto.
   - Blocos `case` podem conter o código simples de interação já usado no projeto, mas não novas funções locais.

4. **Mantenha o encapsulamento do TAD.**
   - A `struct` do nó permanece definida no arquivo `.c`.
   - O `.h` expõe apenas os protótipos necessários.
   - Não acesse campos internos da estrutura fora do TAD.

5. **Siga o padrão do projeto.**
   - Use nomes, retornos, mensagens e estilo semelhantes aos já existentes.
   - Ao implementar algo que já existe em outro módulo, espelhe o padrão desse módulo.
   - Exemplo: os cases de impressão de `buscaTendencia` devem seguir os cases correspondentes de `banimentoJogos`.

6. **Prefira edições pontuais.**
   - Use alterações localizadas em vez de reescrever arquivos inteiros.
   - Não substitua um arquivo completo quando for possível editar apenas o trecho necessário.
   - Preserve formatação, indentação, quebras de linha e codificação existentes.

7. **Reutilize o que já existe.**
   - Antes de criar uma função ou campo, verifique se já há algo equivalente.
   - Reaproveite funções como `emOrdem_ArvAVL`, `emOrdem_NoArvAVL`, `consulta_ArvAVL`, etc.
   - Evite duplicação de lógica.

8. **Não altere código não relacionado.**
   - Trate arquivos e alterações não rastreadas como trabalho do usuário.
   - Não remova, renomeie ou sobrescreva nada fora do escopo do pedido.

9. **Preserve o comportamento existente.**
   - Opções de menu que já funcionavam devem continuar funcionando.
   - Ao encerrar o programa, mantenha a impressão final já definida no módulo, salvo pedido explícito em contrário.
   - Não renomeie opções sem que isso seja solicitado.

10. **Valide a alteração.**
    - Compile com `gcc -std=c99 -Wall -Wextra`.
    - Corrija avisos gerados pelo próprio código alterado.
    - Execute o teste do módulo quando existir (`teste.txt`, `teste_jogadores.txt`, etc.).
    - Se o teste usar uma numeração de menu desatualizada, informe isso ao usuário; não altere o teste sem pedido.

## Fluxo esperado

1. Ler o arquivo alvo e o arquivo de referência, se houver.
2. Identificar a menor alteração possível.
3. Editar apenas o trecho necessário.
4. Compilar.
5. Executar o teste disponível.
6. Relatar de forma curta o que mudou e o resultado da validação.

## O que evitar

- Reescrever módulos inteiros.
- Introduzir padrões ou bibliotecas não usados no restante do repositório.
- Criar funções dentro da `main`.
- Fazer "melhorias" não solicitadas.
- Mudar a estrutura da árvore ou a API do TAD sem necessidade.
- Alterar menus ou testes além do escopo pedido.
