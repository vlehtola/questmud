inherit "/obj/monster";

reset(arg) {
  string chat_str, a_chat_str;
  int i;
  ::reset(arg);
  if(arg) return;
  i = random(2);
  set_level(40+i*4);
  set_name("elf");
  set_alias("dark elf");
  set_short("A very old dark elf retired from duties");
  set_long("A very old dark elf is retired from his duties, and now he got nothing\n"+
           "to do. Therefore he has come in the sepulch, probably trying suicide\n"+
           "to end his misery. The years have treated him well, his skin isn't\n"+
           "wrinkled, his hair is blond, not grey and he is in perfect shape.\n");

  set_race("dark elf");
  set_gender(1);
  set_al(100);
  set_exp(query_exp()+(query_exp()/100));

  if (!chat_str) {
    chat_str = allocate(2);
    chat_str[0] = "Dark elf says: 'I'm retired, and now I got nothing to do.'\n";
    chat_str[1] = "The dark elf puts his hands behind his back,\n"+
                  "lowers his eyes and starts walking around the sepulch.\n";
  }
  if (!a_chat_str) {
    a_chat_str = allocate(1);
    a_chat_str[0] = "Dark elf says: 'Just end my misery!'\n";
  }
  load_chat(15, chat_str);
  load_a_chat(45, a_chat_str);
}