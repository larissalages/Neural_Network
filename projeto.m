clear

%---------------------------------------------------------------------
%DEFINIÇÃO DOS CONJUNTOS DE PARÂMETROS E VALORES DEFAULT
%---------------------------------------------------------------------

%Conjunto de valores pra variar
fileTreino            = {'treino_oversampling.txt', 'treino_undersampling.txt', 'treino_undersamplingKM.txt', 'treino_oversamplingSMT.txt', 'treino_oversamplingSMTadp.txt'};
fileValidacao         = {'validacao_oversampling.txt', 'validacao_undersampling.txt', 'validacao_undersamplingKM.txt', 'validacao_oversamplingSMT.txt', 'validacao_oversamplingSMTadp.txt'};
fileTeste             = 'teste.txt';
amostrasTreino        = [40000, 700, 700, 40000, 40000];   
amostrasValidacao     = [20000, 350, 350, 20000, 20000];    
amostrasTeste         = 10175;  
neuroniosEscondidos   = [10, 20, 40, 60]; 
taxaAprendizado       = [0.2, 0.4, 0.6, 0.8];
funcaoAtivacao        = {'tansig', 'logsig', 'purelin'};
algoritmoAprendizagem = {'traingdm', 'trainlm', 'trainoss'};

%Valores default
fileTr = 'treino_oversampling.txt';
fileVal = 'validacao_oversampling.txt';
sampTr = 40000;
sampVal = 20000;
neuHidden = 10;
taxaApr = 0.2;
funcAtiv = 'tansig';
algoApren = 'traingdm';

%---------------------------------------------------------------------
%VARIA OS PARÂMETROS E ESCOLHE O MELHOR DE CADA
%---------------------------------------------------------------------

%Varia a taxa de aprendizagem e numero de neuronios ocultos
tempAUCteste = 0; %A area tem que ser a maior possivel
tempPorcentAcertos = 0; %tem que ser o maior valor possivel
tempMSEteste = 9999999; %tem que ser o menor possivel

for i = 1 : length(taxaAprendizado)
    for j = 1 : length(neuroniosEscondidos)
        taxa = taxaAprendizado(i);
        neuronios = neuroniosEscondidos(j);
        [MSEtreino, MSEvalidacao, MSEteste, verdadeirosPositivos, verdadeirosNegativos, falsosPositivos, falsosNegativos, AUC] = mlp(fileTr, fileVal, fileTeste, sampTr, sampVal, amostrasTeste, neuronios, taxa, funcAtiv, algoApren);
        
        PorcentAcertos = 100*(verdadeirosPositivos+verdadeirosNegativos)/(amostrasTeste);
        
        if(AUC > tempAUCteste)
            tempAUCteste = AUC;
            tempPorcentAcertos = PorcentAcertos;
            tempMSEteste = MSEteste;
            taxaApr = taxa;
            neuHidden = neuronios;
        elseif((AUC == tempAUCteste) && (PorcentAcertos > tempPorcentAcertos))
            tempPorcentAcertos = PorcentAcertos;
            tempMSEteste = MSEteste;
            taxaApr = taxa;
            neuHidden = neuronios;
        elseif((AUC == tempAUCteste) && (PorcentAcertos == tempPorcentAcertos) && (MSEteste < tempMSEteste))
            tempMSEteste = MSEteste; 
            taxaApr = taxa;
            neuHidden = neuronios;
        end
    end
end


%Varia a funcao de ativacao
tempAUCteste = 0; %A area tem que ser a maior possivel
tempPorcentAcertos = 0; %tem que ser o maior valor possivel
tempMSEteste = 9999999; %tem que ser o menor possivel

for i = 1 : length(funcaoAtivacao)
    funcao = cell2mat(funcaoAtivacao(i));
    [MSEtreino, MSEvalidacao, MSEteste, verdadeirosPositivos, verdadeirosNegativos, falsosPositivos, falsosNegativos, AUC] = mlp(fileTr, fileVal, fileTeste, sampTr, sampVal, amostrasTeste, neuHidden, taxaApr, funcao, algoApren);
        
    PorcentAcertos = 100*(verdadeirosPositivos+verdadeirosNegativos)/(amostrasTeste);
        
    if(AUC > tempAUCteste)
        tempAUCteste = AUC;
        tempPorcentAcertos = PorcentAcertos;
        tempMSEteste = MSEteste;
        funcAtiv = funcao;
    elseif((AUC == tempAUCteste) && (PorcentAcertos > tempPorcentAcertos))
        tempPorcentAcertos = PorcentAcertos;
        tempMSEteste = MSEteste;
        funcAtiv = funcao;
    elseif((AUC == tempAUCteste) && (PorcentAcertos == tempPorcentAcertos) && (MSEteste < tempMSEteste))
        tempMSEteste = MSEteste; 
        funcAtiv = funcao;
    end
end


%Varia o algoritmo de aprendizagem
tempAUCteste = 0; %A area tem que ser a maior possivel
tempPorcentAcertos = 0; %tem que ser o maior valor possivel
tempMSEteste = 9999999; %tem que ser o menor possivel

for i = 1 : length(algoritmoAprendizagem)
    algoritmo = cell2mat(algoritmoAprendizagem(i));
    [MSEtreino, MSEvalidacao, MSEteste, verdadeirosPositivos, verdadeirosNegativos, falsosPositivos, falsosNegativos, AUC] = mlp(fileTr, fileVal, fileTeste, sampTr, sampVal, amostrasTeste, neuHidden, taxaApr, funcAtiv, algoritmo);
        
    PorcentAcertos = 100*(verdadeirosPositivos+verdadeirosNegativos)/(amostrasTeste);
        
    if(AUC > tempAUCteste)
        tempAUCteste = AUC;
        tempPorcentAcertos = PorcentAcertos;
        tempMSEteste = MSEteste;
        algoApren = algoritmo;
    elseif((AUC == tempAUCteste) && (PorcentAcertos > tempPorcentAcertos))
        tempPorcentAcertos = PorcentAcertos;
        tempMSEteste = MSEteste;
        algoApren = algoritmo;
    elseif((AUC == tempAUCteste) && (PorcentAcertos == tempPorcentAcertos) && (MSEteste < tempMSEteste))
        tempMSEteste = MSEteste; 
        algoApren = algoritmo;
    end
end


%Varia arquivos utilizados
tempAUCteste = 0; %A area tem que ser a maior possivel
tempPorcentAcertos = 0; %tem que ser o maior valor possivel
tempMSEteste = 9999999; %tem que ser o menor possivel

for i = 1 : length(fileTreino)
    myfileTr = cell2mat(fileTreino(i));
    myfileVal = cell2mat(fileValidacao(i));
    mysampTr = amostrasTreino(i);
    mysampVal = amostrasValidacao(i);
    [MSEtreino, MSEvalidacao, MSEteste, verdadeirosPositivos, verdadeirosNegativos, falsosPositivos, falsosNegativos, AUC] = mlp(myfileTr, myfileVal, fileTeste, mysampTr, mysampVal, amostrasTeste, neuHidden, taxaApr, funcAtiv, algoApren);
        
    PorcentAcertos = 100*(verdadeirosPositivos+verdadeirosNegativos)/(amostrasTeste);
        
    if(AUC > tempAUCteste)
        tempAUCteste = AUC;
        tempPorcentAcertos = PorcentAcertos;
        tempMSEteste = MSEteste;
        fileTr = myfileTr;
        fileVal = myfileVal;
        sampTr = mysampTr;
        sampVal = mysampVal;
    elseif((AUC == tempAUCteste) && (PorcentAcertos > tempPorcentAcertos))
        tempPorcentAcertos = PorcentAcertos;
        tempMSEteste = MSEteste;
        fileTr = myfileTr;
        fileVal = myfileVal;
        sampTr = mysampTr;
        sampVal = mysampVal;
    elseif((AUC == tempAUCteste) && (PorcentAcertos == tempPorcentAcertos) && (MSEteste < tempMSEteste))
        tempMSEteste = MSEteste; 
        fileTr = myfileTr;
        fileVal = myfileVal;
        sampTr = mysampTr;
        sampVal = mysampVal;
    end
end


%---------------------------------------------------------------------------------------------------------------- 
% %---------------------------------------------------------------------
% % RODA A REDE COM OS MELHORES PARAMETROS E MOSTRA AS ESTATÍSTICAS
% %---------------------------------------------------------------------
%----------------------------------------------------------------------------------------------------------------

%Roda a rede
[MSEtreino, MSEvalidacao, MSEteste, verdadeirosPositivos, verdadeirosNegativos, falsosPositivos, falsosNegativos, AUC] = mlp(fileTr, fileVal, fileTeste, sampTr, sampVal, amostrasTeste, neuHidden, taxaApr, funcAtiv, algoApren);

%Erro médio quadratico
display('Erro medio quadratico (MSE):');
display(['Conjunto de treino: ' num2str(MSEtreino)]);
display(['Conjunto de validacao: ' num2str(MSEvalidacao)]);
display(['Conjunto de teste: ' num2str(MSEteste)]);
display('------------------------------------------------');

%Dados de acertos e erros
display('Erros e acertos:');
display(['Total de casos testados: ' num2str(amostrasTeste)]);
display(['Casos em que acertou: ' num2str(verdadeirosPositivos+falsosNegativos)]);
display(['Casos em que errou: ' num2str(verdadeirosNegativos+falsosPositivos)]);
display(['Verdadeiros Positivos: ' num2str(verdadeirosPositivos)]);
display(['Verdadeiros Negativos: ' num2str(verdadeirosNegativos)]);
display(['Falsos Positivos: ' num2str(falsosPositivos)]);
display(['Falsos Negativos: ' num2str(falsosNegativos)]);
display('------------------------------------------------');

%Valores utilizados para os parametros
display('Melhores parametros:');
display(['Taxa de aprendizado: ' num2str(taxaApr)]);
display(['Neuronios na camada intermediaria: ' num2str(neuHidden)]);
display(['Funcao de ativacao: ' funcAtiv]);
display(['Algoritmo de aprendizagem: ' algoApren]);
display(['Conjunto de treinamento: ' fileTr]);
display('------------------------------------------------');

%Pra fazer a matriz de confusao pro slide
PorcentVerdPosit = 100*(verdadeirosPositivos)/(amostrasTeste);
PorcenVerdNegat =  100*(verdadeirosNegativos)/(amostrasTeste);
PorcentFalsPosit = 100*(falsosPositivos)/(amostrasTeste);
PorcentFalsNegat = 100*(falsosNegativos)/(amostrasTeste);

display('Matriz de Confusao: (Em porcentagem)');
display(['Verdadeiros Positivos: ' num2str(PorcentVerdPosit)]);
display(['Verdadeiros Negativos: ' num2str(PorcenVerdNegat)]);
display(['Falsos Positivos: ' num2str(PorcentFalsPosit)]);
display(['Falsos Negativos: ' num2str(PorcentFalsNegat)]);

%Área sobre a curva ROC
display(['Area Sob a Curva ROC (AUC): ' num2str(AUC)]);