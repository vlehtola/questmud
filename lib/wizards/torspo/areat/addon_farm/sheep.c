inherit "obj/monster";
reset(arg) {
    int i;
    string str, chat_str;
    ::reset(arg);
    if(arg) { return; }
    i = random(7);
    if(i==0) { str = "A black sheep"; }
    if(i==1) { str = "A white lamb"; }
    else { str = "A white fat sheep"; }

    set_level(random(5)+13);
    set_name("sheep");
   if(i==1) { set_alias("lamb"); }
    set_short(""+str+"");
    set_long("The sheep is standing with its small, thin legs. It has some warm\n"+
             "wool on it but party of it has been cut. Sheep has a quite big head\n"+
             "and it looks extremely stupid.\n");
    set_gender(0);
    set_animal();
        if (!chat_str) {
                chat_str = allocate(2);
                chat_str[0] =
        "Sheep eats some grass.\n";
            }
            load_chat(3, chat_str);
}
