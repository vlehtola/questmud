short() { return "A small sign is on the ground"; }
 
long(str) {
write("                City of Gnael\n");
write("--------------------------------------------\n");
write("#####################Gt#####################\n");
write("####################|  |####################\n");
write("########|Sh|  |Sh|##|  |#####|Th|Th|Th|#####  Cs = Central square\n");
write("###########|  |#####|  |#####|Th|Th|Th|#####  Ga = Garden\n");
write("###########|  |  |  |  |  |  |Th|Th|Th|#####  Ma = Mansion\n");
write("###########|  |#####|  |########|  |########  Ho = House\n");
write("###########|  |#####|  |########|  |########  Sh = Shop\n");
write("Gt|  |  |  |  |  |  |Cs|  |  |  |  |  |  |Gt  Th = Townhall\n");
write("##|Ho|  |###########|  |##|  |##############  Gt = Gate\n");
write("#####|  |  |  |  |  |  |##|  |Ho|###########\n");
write("##|  |  |Ga|Ma|Ma|Ma|  |  |  |##|Sh|########\n");
write("#####|  |Ga|Ma|Ma|Ma|  |##|  |  |  |Sh|#####\n");
write("#####|  |  |  |  |  |  |########|Sh|########\n");
write("########|Ho|########|  |Ho|#################\n");
write("#####################Gt#####################\n");
write("--------------------------------------------\n");
write("Please enjoy your visit in our city.\n");
write("We have made this map, so you would\n");
write("not get lost so easily, but remember\n");
write("that we mapped only the places that\n");
write("are most commonly used.\n");
    return;
}
 
id(str) { return str == "sign"; }
 
get(str) {
    if (str == "sign") {
        write("You can't take the sign.\n");
        return 0;
    }
    return 0;
}
