inherit "obj/monster";
reset(arg) {
        ::reset(arg);
        if(arg) {return; }
        set_name("santa");
        set_alias("santa claus");
        set_level(30);
        set_gender(1);
        set_short("An santa claus wearing red clothes");
        set_long("He is wearing a red clothes and red tonttulakki with a small kulkunen .\n"+
                 "at the top of hat. He is a quite big fellow. He has a long white bear.\n");
}

self_destruct() {
destruct(present("santa",find_object("/world/city/cs")));
        destruct(this_object());
}