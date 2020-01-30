short() { return "A sign is leaning against the hillside"; }

long(str) {
    write("/-----+-----\\\n"+
          "|           |\n"+
          "|  O R C S  |\n"+
          "| yu no com |\n"+
          "|           |\n"
         "\\-----+-----/\n");
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
