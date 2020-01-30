init() {
  add_action("read", "read");
}

short() { return "A leather book with a large 'L' on the cover"; }

long(str) {
    write("This is a dusty book with leather boundings. It seems to\n"+
          "contain instructions about some old language. You have\n"+
          "never seen such writing anywhere. The big 'L' on the cover\n"+
          "implies that the name of the language starts with an 'L'.\n"+
          "The book looks very old but it's only a bit worn.\n");
    return;
}

id(str) { return str == "book" || str == "book123";}

get() {
    return 1;
}

query_weight() {
  return 300;
}


read(str) {
        if(!str) { return; }
        if(present(str) == this_object()) {
                write(  "You peruse through the pages and, although they are\n"+
                        "a bit worn, you find the following words:\n"+
                        " custos   -  guard\n"+
                        " deus     -  god\n"+
                        " glacies  -  ice\n"+
                        " gladius  -  sword\n"+
                        " lux      -  light\n"+
                        " pax      -  peace\n"+
                        " pater    -  father\n"+
                        " porta    -  portal\n"+
                        " ventus   -  wind\n"+
                        " venenum  -  poison\n");
                return 1;
        }
}
