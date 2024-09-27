for file in ./reports/*;
  do if [[ -f $file ]];
    then
      java -jar ./validator_1_5_0/validationtool-1.5.0-standalone.jar -s validator-configuration-xrechnung_3_0_2/scenarios.xml -r validator-configuration-xrechnung_3_0_2/ -h "$file" 2>&1 | tee output.log;
      if ! grep -q "Validation successful" output.log;
        then break;
      fi;
    fi;
  done