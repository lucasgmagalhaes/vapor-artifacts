# vapor-artifacts

Build e hospedagem dos artefatos (wasm + assets livres) dos jogos listados no catálogo do [Vapor](https://github.com/lucasgmagalhaes/vapor).

- Cada jogo tem um workflow em `.github/workflows/build-<slug>.yml` que compila a partir de um commit **fixado** do código-fonte, verifica o hash dos assets e publica um Release (`<slug>-<n>`).
- O catálogo (`games/<slug>/game.json` no repositório `vapor`) aponta para a URL do Release e guarda o `sha256` e o `size`. O app confere ambos antes de instalar.
- Só entram jogos com `assets_policy` `open` (código e assets com licença livre) ou o código de jogos `bring-your-own`, nunca assets proprietários.
- **Remoção:** pedidos de takedown são tratados no repositório `vapor` (veja `takedown/TAKEDOWN.md`); aqui basta apagar o Release (e o workflow) do jogo.
