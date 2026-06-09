# jogo-Dungeon-Crawler
#  DUNGEON CRAWLER

> Um jogo de exploração de masmorras em C, jogado no terminal.

---

##  Desenvolvedor

**Luiz Fernando Almeida Lima**

---

## História

Em uma vila pacata nos arredores da floresta, rumores se espalhavam sobre a lendária **Masmorra Haguromo** — um lugar sombrio onde poucos entraram e quase ninguém voltou.

Dizem os moradores que no fundo da masmorra existe um tesouro guardado pelo temido **Lorde Orc**, uma criatura brutal que domina as profundezas há décadas.

Você é um jovem aventureiro que decide enfrentar esse desafio. Antes de partir, a ferreireira **Laufey** te oferece uma arma. Pelo caminho, você encontrará aliados que te contarão mais sobre o perigo que te aguarda — e uma misteriosa **Maga Megera** que pode encantar sua arma antes do confronto final.

Será que você tem coragem suficiente para enfrentar o Lorde Orc e sair vivo da Masmorra Haguromo?

---

## Como Jogar

### Objetivo
Explore a vila, entre na masmorra, avance pelos andares e derrote o **Lorde Orc** no andar final.

### Controles

| Tecla | Ação |
|-------|------|
| `w` | Mover para cima |
| `a` | Mover para a esquerda |
| `s` | Mover para baixo |
| `d` | Mover para a direita |
| `i` | Interagir com o objeto à frente |
| `o` | Atacar a área à frente |

### Dicas
- Fale com os NPCs antes de entrar na masmorra — eles têm informações importantes.
- Use a chave `@` para abrir portas `D`.
- Destrua caixas `k` com o ataque para encontrar itens.
- Cuidado com espinhos `#` — eles tiram uma vida ao passar por cima.
- Visite a Maga Megera antes do boss para encantar sua arma.

---

## Estrutura do Jogo

```
Vila → Andar 1 → Andar 2 → Sala da Maga → Andar 3 (Boss)
```

| Fase | Local | Descrição |
|------|-------|-----------|
| 0 | Vila | Área inicial. Converse com NPCs e escolha sua arma. |
| 1 | Andar 1 | Tutorial da masmorra. Chave, porta e caixas. |
| 2 | Andar 2 | Espinhos, monstros e armadilhas. |
| 3 | Sala da Maga | Encantar a arma e abrir a porta para o boss. |
| 4 | Andar 3 | Confronto final com o Lorde Orc. |

---

##  Significado dos Símbolos

| Símbolo | Significado |
|---------|-------------|
| `^` `v` `<` `>` | Jogador (indica a direção que está olhando) |
| `*` | Parede — não é possível passar |
| `#` | Espinho — tira 1 vida ao passar por cima |
| `k` | Caixa — bloqueia passagem, pode ser destruída com ataque |
| `O` | Botão — executa uma ação ao interagir |
| `D` | Porta fechada — precisa de uma chave para abrir |
| `=` | Porta aberta — pode passar |
| `@` | Chave — abre uma porta fechada |
| `L` | Escada — leva para o próximo andar |
| `X` | Monstro Tipo 1 — movimento aleatório |
| `Y` | Monstro Tipo 2 — persegue o jogador |
| `Z` | Boss Final — Lorde Orc |
| `F` | Ferreireira Laufey (NPC) |
| `A` | Philip (NPC) |
| `B` | Joffrey (NPC) |
| `M` | Maga Megera (NPC) |
| `$` | Drop de item — coletável |

---

##  Armas

| Arma | Área de Ataque | Nível 2 (encantada) |
|------|---------------|----------------------|
| Espada | 3×2 células à frente | 3×3 células à frente |
| Arco | 4 células em linha reta | 6 células em linha reta |
| Cajado | 8 células ao redor | 8 células + 2 extras na direção que olha |

---

## Sistema de Vidas

- O jogador possui **3 vidas**.
- Perde 1 vida ao pisar em espinho `#` ou ser tocado por um monstro.
- Ao perder todas as vidas, aparece a tela de **Game Over**.

---

##  Como Compilar e Executar

### Requisitos
- Windows
- GCC (MinGW)

### Compilar
```bash
gcc main.c -o dungeon_crawler.exe
```

### Executar
```bash
./dungeon_crawler.exe
```

---

##  Uso de IA Generativa

Este projeto utilizou **IA generativa (Claude - Anthropic)** como ferramenta de apoio ao aprendizado durante o desenvolvimento.

A IA foi utilizada para:
- Auxiliar na compreensão de funções e conceitos da linguagem C
- Identificar e explicar bugs no código
- Sugerir estruturas de implementação para mecânicas do jogo
- Tirar dúvidas sobre sintaxe e lógica de programação

Todo o código foi compreendido, adaptado e escrito pelo desenvolvedor. A IA serviu como uma ferramenta de consulta, similar a uma documentação interativa.

---

##  Disciplina

Projeto desenvolvido para a disciplina de **Programação** — trabalho prático de implementação em linguagem C.
