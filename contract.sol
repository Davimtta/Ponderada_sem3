// SPDX-License-Identifier: MIT
pragma solidity >=0.6.12 <0.9.0;

// Declaração do contrato NovoProduto
contract NovoProduto {

  // Definição da estrutura Produto
  struct Produto {
    uint256 precoProduto; // Preço do produto
    string nomeProduto; // Nome do produto
  }
  
  // Declaração de uma matriz pública de produtos
  Produto[] public produtos;

  // Função para adicionar um novo produto à matriz de produtos
  function novoProduto(uint256 _precoProduto, string memory _nomeProduto) external {
      // Adiciona um novo produto à matriz de produtos
      produtos.push(Produto({
        precoProduto: _precoProduto,
        nomeProduto: _nomeProduto
      }));
  }
  
}
