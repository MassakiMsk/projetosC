#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 20
#define quantidade 10

int model(char modelo[tamanho], char modeloAux[tamanho], char atributos[quantidade][tamanho], char atributosAux[quantidade][tamanho]) {
    int atr_qnt = 0, i;
    char aux[tamanho];
    FILE *file = NULL;

    printf("Nome do modelo: ");
    scanf("%s%*c", modelo);

    strcpy(modeloAux, modelo);
    modeloAux[0] -= 32;

    sprintf(aux, "%ssModel.js", modelo);

    if((file = fopen(aux, "w")) == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }

    printf("Insira os atributos (000 para finalizar):\n");
    while(1) {
        printf("\t");
        scanf("%s%*c", atributos[atr_qnt]);
        if(strcmp(atributos[atr_qnt], "000") == 0)
            break;
        strcpy(atributosAux[atr_qnt], atributos[atr_qnt]);
        strupr(atributosAux[atr_qnt]);
        atr_qnt++;
    }

    fprintf(file, "'use strict';\n\n");
    fprintf(file, "module.exports = () => {\n");
    fprintf(file, "\tconst get%ss = (connection) => {\n", modeloAux);
    fprintf(file, "\t\treturn connection.%ss;\n", modelo);
    fprintf(file, "\t};\n\n");

    fprintf(file, "\tconst get%s = (%sInfo, connection) => {\n\n", modeloAux, modelo);

    fprintf(file, "\t};\n\n");

    fprintf(file, "\tconst create%s = (%s, connection) => {\n", modeloAux, modelo);
    fprintf(file, "\t\t%ss = connection.%ss;\n", modelo, modelo);
    fprintf(file, "\t\t%ss.push({\n", modelo);
    fprintf(file, "\t\t\tID: %ss.length + 1,\n", modelo);

    for(i = 0; i < atr_qnt - 1; i++) {
        fprintf(file, "\t\t\t%s: %s.%s,\n", atributosAux[i], modelo, atributos[i]);
    }
    fprintf(file, "\t\t\t%s: %s.%s\n", atributosAux[i], modelo, atributos[i]);

    fprintf(file, "\t\t});\n");
    fprintf(file, "\t\treturn %ss[%ss.length-1];\n", modelo, modelo);
    fprintf(file, "\t};\n\n");

    fprintf(file, "\tconst edit%s = (%s, connection) => {\n", modeloAux, modelo);
    fprintf(file, "\t\tlet %ss = connection.%ss;\n", modelo, modelo);
    fprintf(file, "\t\tlet flag = false;\n");
    fprintf(file, "\t\t%ss.forEach(e => {\n", modelo);
    fprintf(file, "\t\t\tif(e.ID === %s.id) {\n", modelo);

    for(i = 0; i < atr_qnt; i++) {
        fprintf(file, "\t\t\t\tif(%s.%s) {\n", modelo, atributos[i]);
        fprintf(file, "\t\t\t\t\te.%s = %s.%s;\n", atributosAux[i], modelo, atributos[i]);
        fprintf(file, "\t\t\t\t}\n");
    }

    fprintf(file, "\t\t\t\tflag = true;\n");
    fprintf(file, "\t\t\t} \n");
    fprintf(file, "\t\t});\n");
    fprintf(file, "\t\treturn flag ? {status: `%s #${%s.id} update`} : {status: `%s #${%s.id} not found`};\n", modeloAux, modelo, modeloAux, modelo);
    fprintf(file, "\t};\n\n");

    fprintf(file, "\tconst delete%s = (%s, connection) => {\n\n", modeloAux, modelo);

    fprintf(file, "\t};\n\n");

    fprintf(file, "\treturn {\n");
    fprintf(file, "\t\tget%ss: get%ss,\n", modeloAux, modeloAux);
    fprintf(file, "\t\tget%s: get%s,\n", modeloAux, modeloAux);
    fprintf(file, "\t\tcreate%s: create%s,\n", modeloAux, modeloAux);
    fprintf(file, "\t\tedit%s: edit%s,\n", modeloAux, modeloAux);
    fprintf(file, "\t\tdelete%s: delete%s\n", modeloAux, modeloAux);
    fprintf(file, "\t};\n");
    fprintf(file, "}");

    fclose(file);
    return atr_qnt;
}

void service(char modelo[tamanho], char modeloAux[tamanho]) {
    char aux[tamanho];
    FILE *file = NULL;

    sprintf(aux, "%ssService.js", modelo);

    if((file = fopen(aux, "w")) == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }

    fprintf(file, "'use strict';\n\n");

    fprintf(file, "const model = require('./%ssModel')();\n\n", modelo);

    fprintf(file, "module.exports = () => {\n");
    fprintf(file, "\tconst get%ss = connection => {\n", modeloAux);
    fprintf(file, "\t\treturn model.get%ss(connection);\n", modeloAux);
    fprintf(file, "\t};\n\n");

    fprintf(file, "\tconst get%s = (%sInfo, connection) => {\n\n", modeloAux, modelo);

    fprintf(file, "\t};\n\n");

    fprintf(file, "\tconst create%s = (%s, connection) => {\n", modeloAux, modelo);
    fprintf(file, "\t\treturn model.create%s(%s, connection);\n", modeloAux, modelo);
    fprintf(file, "\t};\n\n");

    fprintf(file, "\tconst edit%s = (%s, connection) => {\n", modeloAux, modelo);
    fprintf(file, "\t\treturn model.edit%s(%s, connection);\n", modeloAux, modelo);
    fprintf(file, "\t};\n\n");

    fprintf(file, "\tconst delete%s = (%s, connection) => {\n\n", modeloAux, modelo);

    fprintf(file, "\t};\n\n");

    fprintf(file, "\treturn {\n");
    fprintf(file, "\t\tget%ss: get%ss,\n", modeloAux, modeloAux);
    fprintf(file, "\t\tget%s: get%s,\n", modeloAux, modeloAux);
    fprintf(file, "\t\tcreate%s: create%s,\n", modeloAux, modeloAux);
    fprintf(file, "\t\tedit%s: edit%s,\n", modeloAux, modeloAux);
    fprintf(file, "\t\tdelete%s: delete%s\n", modeloAux, modeloAux);
    fprintf(file, "\t};\n");
    fprintf(file, "}");

    fclose(file);
}

int main()
{
    char modelo[tamanho], modeloAux[tamanho], atributos[quantidade][tamanho], atributosAux[quantidade][tamanho];
    int atr_qnt = 0, i;

    atr_qnt = model(modelo, modeloAux, atributos, atributosAux);
    service(modelo, modeloAux);
}
