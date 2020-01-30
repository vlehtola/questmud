inherit "obj/monster";


reset(arg) {
  string chat_str, a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_name("dealer");
  set_alias("mentor");
  set_level(90);
  set_log();
  set_gender(1);
  set_race("human");
  set_str(query_str()*2);
  set_exp(8000000);
  set_block_dir("backroom");
  set_short("Mentor Wormskin, the bait dealer");
  set_long("Mentor Wormskin is the island's bait dealer. He delivers worms for\n" +
           "fishermen and everybody who needs them. He was a fisherman earlier,\n" +
           "but nowadays he's the bait dealer. He's is about sixty years old\n"+
           "and very thin. An anchor is tattooed on his right hand.\n");


if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
"Dealer says: 'Type 'list' if you wan't to buy some baits.'\n";
        chat_str[1] =
"Dealer says: 'There's a small beach on the island where you can get fish more than you need!'\n";

    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Dealer says: 'You'll end to wormfood!'\n";
    }
    load_chat(5, chat_str);
    load_a_chat(3, a_chat_str);
}
