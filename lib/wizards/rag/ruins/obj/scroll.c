init() {
  add_action("chant", "chant");
  add_action("read", "read");
}

short() { return "An old wrinkled scroll"; }

long(str) {
    write("This is an old wrinkled scroll. It is filled with strange\n"+
        "markings, perhaps some old language that was long forgotten.\n"+
        "It is glowing faintly.\n");
    return;
}

id(str) { return str == "scroll" || str == "scroll123"; }

get() {
    return 1;
}

query_weight() {
  return 1;
}

chant(str) {
        if(!str) {
                write("Use: chant <word>\n");
                return 1;
        }
        str = lower_case(str);
        write("You chant the magic word: "+str+"\n");
        say(this_player()->query_name()+ " chants the magic word: "+str+"\n");
        if(str == "gladius") {
                write("You get the feeling that a powerful sword is buried somewhere near the church.\n");
                return 1;
        }
        call_other(environment(this_player()),"chant",str);
        return 1;
}

read(str) {
        string *texts;
        if ( !str ) { return; }
        texts = ({"In vino veritas.","In hoc signo vinces.","Qualis rex, talix grex.","Mens sana in corpore sano.",
                "Vitia ne excusemus, sed vitemus.","Vestigia terrent.","Divide et impera!",
                "Errare humanum est, et confiteri errorem prudentis.","Nosce te ipsum!"});
        if(present(str) == this_object()) {
                write("You read a sentence from the scroll:\n"+texts[random(sizeof(texts))]+"\n");
                return 1;
        }
}
