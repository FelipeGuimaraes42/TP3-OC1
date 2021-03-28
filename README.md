Existe duas opções para a execução do código :

. Via script bash "run.sh", o qual executa por padrão o caso teste passado na especificação do trabalho, mas também aceita inputs (run.sh input_file)
. Via makefile :
    . make run roda o caso padrão, semelhante ao bash
    . make, depois ./tp3 input_file.txt roda o arquivo que deseja.

Em todos os casos o resultado estará no arquivo result.txt , no diretório output. 