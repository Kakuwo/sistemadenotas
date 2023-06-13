typedef struct {
  char nome[100];
  int matricula;
  char curso[50];
  float av1;
  float av2;
  float av3;
  float media;
} Aluno;

Aluno alunos[100];
int totalAlunos = 0;

// Função para adicionar um novo aluno ao cadastro
void adicionarAluno() {
  system("clear");

  if (totalAlunos == 100) {
    printf("Número máximo de alunos cadastrados atingido.\n");
    return;
  }

  Aluno novoAluno;

  printf("Nome: ");
  fgets(novoAluno.nome, 100,
        stdin); // Stdin é uma entrada de dados "padrão" do fgets
  strtok(novoAluno.nome, "\n"); // Remover a quebra de linha do final do nome

  printf("Matrícula: ");
  scanf("%d", &novoAluno.matricula);
  getchar(); // Limpar o buffer do teclado

  // Verificar se a matrícula já existe
  int i; 
  for (i = 0; i < totalAlunos; i++) {
    if (alunos[i].matricula == novoAluno.matricula) {
      printf("Já existe um aluno cadastrado com a matrícula informada.\n");
      return;
    }
  }

  printf("Curso: ");
  fgets(novoAluno.curso, 50, stdin);
  strtok(novoAluno.curso, "\n"); // Remover a quebra de linha do final do curso

  printf("AV1: ");
  scanf("%f", &novoAluno.av1);
  getchar(); // Limpar o buffer do teclado

  printf("AV2: ");
  scanf("%f", &novoAluno.av2);
  getchar(); // Limpar o buffer do teclado

  printf("AV3: ");
  scanf("%f", &novoAluno.av3);
  getchar(); // Limpar o buffer do teclado

  novoAluno.media = (novoAluno.av1 + novoAluno.av2 + novoAluno.av3) / 3.0;

  alunos[totalAlunos] = novoAluno;
  totalAlunos++;

  printf("Aluno adicionado com sucesso.\n");
}

// Função para calcular a média individual de um aluno
void calcularMediaIndividual() {
  system("clear");

  if (totalAlunos == 0) {
    printf("Não existem alunos cadastrados.\n");
    return;
  }

  int matricula;
  printf("Digite a matrícula do aluno: ");
  scanf("%d", &matricula);
  getchar(); // Limpar o buffer do teclado

  int i;
  for (i = 0; i < totalAlunos; i++) {
    if (alunos[i].matricula == matricula) {
      printf("A média do aluno %s é igual a: %.2f\n", alunos[i].nome,
             alunos[i].media);
      return;
    }
  }

  printf("Aluno não encontrado.\n");
}

// Função para calcular a média geral da turma
void calcularMediaGeral() {
  system("clear");

  if (totalAlunos == 0) {
    printf("Não existem alunos cadastrados.\n");
    return;
  }

  float somaMedias = 0.0;
  int i;
  for (i = 0; i < totalAlunos; i++) {
    somaMedias += alunos[i].media;
  }

  float mediaGeral = somaMedias / totalAlunos;

  printf("A média geral da turma é igual a: %.2f\n", mediaGeral);
}

// Função para exibir os alunos com melhor desempenho
void exibirMelhoresAlunos() {
  system("clear");

  if (totalAlunos == 0) {
    printf("Não existem alunos cadastrados.\n");
    return;
  }

  // Ordenar os alunos por média em ordem decrescente
  int i, j;
  for (i = 1; i < totalAlunos; i++) {
    for (j = 1; j < totalAlunos; j++) {
      if (alunos[j].media < alunos[j + 1].media) {
        Aluno temporario = alunos[j];
        alunos[j] = alunos[j + 1];
        alunos[j + 1] = temporario;
      }
    }
  }

  int quantidade = totalAlunos > 10 ? 10 : totalAlunos;

  printf("Alunos com melhor desempenho:\n");
  for (i = 0; i < quantidade; i++) {
    printf("%dº lugar: %s - Média: %.2f\n", i + 1, alunos[i].nome,
           alunos[i].media);
  }
}

// Função para excluir um aluno dos dados cadastrados
void excluirAluno() {
  system("clear");

  if (totalAlunos == 0) {
    printf("Não existem alunos cadastrados.\n");
    return;
  }

  int matricula;
  printf("Digite a matrícula do aluno a ser excluído: ");
  scanf("%d", &matricula);
  getchar(); // Limpar o buffer do teclado

  int i, j;
  int encontrado = 0;

  for (i = 0; i < totalAlunos; i++) {
    if (alunos[i].matricula == matricula) {
      encontrado = 1;

      // Deslocar os demais alunos para preencher o espaço vazio
      for (j = i; j < totalAlunos - 1; j++) {
        alunos[j] = alunos[j + 1];
      }

      totalAlunos--;

      printf("Aluno excluído com sucesso.\n");
      return;
    }
  }

  if (!encontrado) {
    printf("Aluno não encontrado.\n");
  }
}

// Função para exibir os alunos cadastrados
void exibirAlunosCadastrados() {
  system("clear");

  if (totalAlunos == 0) {
    printf("Não existem alunos cadastrados.\n");
    return;
  }

  int i;

  printf("Alunos cadastrados:\n");
  for (i = 0; i < totalAlunos; i++) {
    printf("Nome: %s\n", alunos[i].nome);
    printf("Matrícula: %d\n", alunos[i].matricula);
    printf("Curso: %s\n", alunos[i].curso);
    printf("\n");
  }
}

// Função para salvar os dados dos alunos em um arquivo
void salvarDadosEmArquivo() {
  FILE *arquivo;
  arquivo = fopen("alunos.csv", "w");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para escrita.\n");
    return;
  }

  int i;

  fprintf(arquivo, "Nome,Matricula,Curso,AV1,AV2,AV3,Media\n");

  for (i = 0; i < totalAlunos; i++) {
    fprintf(arquivo, "%s,%d,%s,%.2f,%.2f,%.2f,%.2f\n", alunos[i].nome,
            alunos[i].matricula, alunos[i].curso, alunos[i].av1, alunos[i].av2,
            alunos[i].av3, alunos[i].media);
  }

  fclose(arquivo);

  printf("Dados salvos no arquivo com sucesso.\n");

  return 0;
}

// Função para ler os dados dos alunos de um arquivo
void lerDadosDeArquivo() {
  FILE *arquivo;
  arquivo = fopen("alunos.csv", "r");

  if (arquivo == NULL) {
    printf("Arquivo não encontrado.\n");
    return;
  }

  char linha[100];

  fgets(linha, sizeof(linha), arquivo); // Ignorar a primeira linha de cabeçalho

  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    char *token;
    token = strtok(linha, ",");

    strcpy(alunos[totalAlunos].nome, token);

    token = strtok(NULL, ",");
    sscanf(token, "%d", &alunos[totalAlunos].matricula);

    token = strtok(NULL, ",");
    strcpy(alunos[totalAlunos].curso, token);

    token = strtok(NULL, ",");
    sscanf(token, "%f", &alunos[totalAlunos].av1);

    token = strtok(NULL, ",");
    sscanf(token, "%f", &alunos[totalAlunos].av2);

    token = strtok(NULL, ",");
    sscanf(token, "%f", &alunos[totalAlunos].av3);

    token = strtok(NULL, ",");
    sscanf(token, "%f", &alunos[totalAlunos].media);

    totalAlunos++;
  }

  fclose(arquivo);
}

// Função para exibir o menu de opções
void exibirMenu() {
  int opcao = 0;

  while (opcao != 8) {
    system("clear");

    printf("Sistema de Gerenciamento de Notas\n");
    printf("---------------------------------\n");
    printf("1. Adicionar novo aluno\n");
    printf("2. Exibir alunos cadastrados\n");
    printf("3. Calcular média individual\n");
    printf("4. Calcular média geral da turma\n");
    printf("5. Exibir alunos com melhor desempenho\n");
    printf("6. Excluir aluno\n");
    printf("7. Salvar dados em arquivo e fechar o programa\n");
    printf("---------------------------------\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); // Limpar o buffer do teclado

    switch (opcao) {
    case 1:
      adicionarAluno();
      break;
    case 2:
      exibirAlunosCadastrados();
      break;
    case 3:
      calcularMediaIndividual();
      break;
    case 4:
      calcularMediaGeral();
      break;
    case 5:
      exibirMelhoresAlunos();
      break;
    case 6:
      excluirAluno();
      break;
    case 7:
      printf("Deseja salvar os dados no arquivo? (S/N): ");
      char resposta;
      scanf("%c", &resposta);
      getchar(); // Limpar o buffer do teclado

      if (resposta == 'S' || resposta == 's') {
        salvarDadosEmArquivo();
      }

      printf("Encerrando o programa...\n");
      break;
      return 0;
    default:
      printf("Opção inválida.\n");
      break;
    }

    printf("Pressione Enter para continuar...\n");
    getchar(); // Aguardar a tecla Enter
  }
}