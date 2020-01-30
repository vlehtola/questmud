inherit "obj/monster";
void reset(status arg) {
    string *chat_str, *a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_name("nixloug");
    set_alias("sorcerer");
    set_short("Nixloug the sorcerer is concentrating on something");
    set_long("This man is dressed in his fearsome dark cloak, and he\n"+
             "seems to be concentrating on something unique, that nobody\n"+
             "has seen ever before. Maybe you should end his dirty deeds\n"+
             "before it gets any further, and possibly save the world.\n"+
             "An invisible aura seems to float around him, with cold feeling.\n");
    set_level(60);
    set_al(-200);
    set_aggressive(0);
    if (!chat_str) {
        chat_str = allocate(10);
        chat_str[0] = "Nixloug says: 'NaZziggiNua ZumDamDim!'\n";
        chat_str[1] = "Nixloug says: 'HirissaAwooomKabUUm!'\n";
        chat_str[2] = "Nixloug says: 'What are you looking at?'\n";
        chat_str[3] = "Nixloug says: 'Get lost before I kill you!'\n";
        chat_str[4] = "Nixloug says: 'AffummaDummaKabuuma ZigizagiPoX!'\n";
        chat_str[5] = "Nixloug says: 'You better start running...'\n";
        chat_str[6] = "Nixloug closes his eyes and continues chanting.\n";
        chat_str[7] = "Nixloug says: 'karkkipussi HeRkKuPuSsI POMMIPUSSI!'\n";
        chat_str[8] = "Nixloug says: 'Try to attack me! What, don't have the guts?'\n";
        chat_str[9] = "Nixloug says: 'I bought one of my bombs from some weird guy,\nand I almost blew myself up!'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Nixloug says: 'You will regret this my child...'\n";
    }
    load_chat(5, chat_str);
    load_a_chat(20, a_chat_str);
    set_special(25);
    move_object(this_object(),"/world/city/cs");
}

hit_with_spell() {
  if(random(5)) return 1;
}

void special_move() {
object ob;
string *tgts;
tgts = ({ "inn.c", "post.c", });
ob = this_object()->query_attack();
if(!random(10) && !present("dimensional gate",environment(this_object()))) {
  say("Nixloug opens the dimensional gate to another world!\n");
  move_object(clone_object("/wizards/garath/dimension/dimgate.c"),environment(this_object()));
}
else if(!random(5)) {
  say("Nixloug mutters: 'ZooooooooooooM ... :: ... Click!'\n");
  say(capitalize(ob->query_real_name())+" suddenly vanishes!\n",ob);
  move_object(ob,"/world/city/"+tgts[random(sizeof(tgts))]);
}
else if(!random(10)) {
  say("Nixloug mutters: 'ZimZumDumPum! ... ::: ... Pick up "+capitalize(ob->query_real_name())+"!'\n");
  say("Death appears in front of "+ob->query_real_name()+" and *SLASHES* with his scythe!\n",ob);
  tell_object(ob,"Death appears in front of you, and *SLASHES* you with his scythe!\n");
  ob->hit_with_spell(2000);
}
else if(!random(10)) {
  say("Nixloug shouts: 'DEMONIUS MAXIMUS!!!'\n");
  move_object(clone_object("/wizards/garath/dimension/demon.c"),find_object("/wizards/garath/dimension/dimension.c"));
}
}
