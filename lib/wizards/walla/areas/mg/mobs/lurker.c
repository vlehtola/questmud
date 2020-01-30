inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_level(21+random(4));
    set_name("lurker");
    set_alias("man");
    set_short("A man, lurking behind the grave");
    set_long("The apparition before you is a strange one. It has the\n"+
             "resemblance of a man, but is not quite human. He has \n"+
             "an elongated face with big eyes, but almost no nose or ears.\n"+
             "It would almost seem that he is not of this world.\n");
    set_al(30);
    set_gender(1);
    


}


