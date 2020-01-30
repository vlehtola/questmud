
inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object armour,wepa;
    int i;
    ::reset(arg);
    if(arg) { return; }
    i = random(2);
    set_level(1);
    set_name("Kekex homo ucko toimaa tai sit ei");
    set_alias("ucko");
    set_short("Kekex ucko");
    set_long("T�� on t�ysin kekex homo ucko joka ei tajuu mit��n mist��n.\n");
    set_race("human");
    set_gender(1);
    set_log();
    set_al(-75);
    set_aggressive(0);
 
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "Ucko says mit� s� oikee s�hl��t siin� keke\n";
        chat_str[1] =
          "Ucko says painu ny vittuun kyyl��m�st� siit�.\n";
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Ucko says no oke oke et oo keke �l� ny vittu rupee mesoon sent��\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
 
    if(i==0) { armour = clone_object("wizards/ozmala/areat/area-testi/ekut/eku");
    move_object(armour, this_object());
    init_command("wear eku");
}    

    if(i==1) { wepa = clone_object("wizards/ozmala/areat/area-testi/ekut/wepa");
    move_object(wepa, this_object());
    init_command("wield wepa");
  }
}