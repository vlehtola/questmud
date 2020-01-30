inherit "obj/monster";


reset(arg) {
  string chat_str, a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_name("bailiff");
  set_alias("niles");
  set_level(90);
  set_log();
  set_gender(1);
  set_race("human");
  set_str(query_str()*2);
  set_exp(8000000);
  set_short("Niles Fishbone, the friendly water bailiff");
  set_long("Niles Fishbone is the water bailiff of the island. He looks friendly\n" +
           "and he's rumoured to be very helpfully. He's selling different stuff\n" +
           "for fishing. He's about fifty years old and almost two meters long.\n");


if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
"Bailiff says: 'Type 'list' if you wan't to buy stuff for fishing.'\n";
        chat_str[1] =
"Bailiff says: 'A have heard that there's this beach where you can get lots of fish!'\n";
        chat_str[2] =       
"Bailiff says: 'It's located on the northwest corner of the island.'\n";

    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Bailiff says: 'I'll throw you to the sharks!'\n";
    }
    load_chat(5, chat_str);
    load_a_chat(3, a_chat_str);
}
