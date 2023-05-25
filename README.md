# Sistema de notas
Um sistema de gerenciamento de notas de alunos usando a linguagem C.

# Descrição do projeto:
O objetivo deste projeto é desenvolver um sistema de gerenciamento de notas dos alunos,
utilizando a linguagem de programação C. 
O sistema permitirá cadastrar alunos, registrar
suas notas (AV1, AV2 e AV3) e realizar operações como calcular média individual, média
geral da turma, exibir alunos com melhor desempenho e salvar as informações em um
arquivo excel.

# Requisitos do projeto:
O programa deve apresentar um menu de opções para o usuário, incluindo as seguintes
funcionalidades:

● Adicionar um novo aluno ao cadastro: O usuário será solicitado a inserir as
informações do aluno, como nome, matrícula e curso.

● Registrar notas do aluno: O usuário poderá registrar as notas do aluno, fornecendo
os valores numéricos das notas.

● Calcular média individual: O programa deve calcular e exibir a média das notas de
um aluno específico, solicitando o nome ou a matrícula do aluno.

● Calcular média geral da turma: O programa deve calcular e exibir a média geral das
notas de todos os alunos cadastrados.

● Exibir alunos com melhor desempenho: O programa deve listar os 10 alunos com as
melhores médias, indicando seus nomes e médias de forma ordenada.

● Salvar informações em um arquivo: O programa deve permitir que as informações
dos alunos e suas notas sejam salvas em um arquivo excel.

● As informações deverão ser mantidas ao fechar e abrir o programa.

# Diário de Bordo:

Dia 1 -

Pesquisei como integrar a linguagem C com o Excel, e descobri a biblioteca: 
libxlsxwriter. Que me permite manipular arquivos XLSX(Excel).

Dia 2 -

Não vou precisar da biblioteca, tenho a saída de usar uma função própria do C.
A "struct" e arquivos '.csv'
