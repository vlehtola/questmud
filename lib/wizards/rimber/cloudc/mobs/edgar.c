inherit "obj/monster";

reset(arg) {
 string chat_str;
 ::reset(arg);
 if(arg) return;
 set_level(10);
 set_name("edgar");
 set_alias("edgar");
 set_race("angel");
 set_al(30);
 set_gender(3);
 set_short("Edgar the knight a Sword (old)");
 set_long("Edgar has a long red cape and bright blue eyes. He is old but might still have\n"+
  "some strength to fight one war more.\n");
 if(!chat_str) {
 chat_str = allocate(3);
 chat_str[0] = "Edgar moans: 'Bring me my sword!'\n";
 chat_str[1] = "Edgar says: 'I can fight. You have to beleave me!'\n";
 chat_str[2] = "Edgar screams: 'Take that you child eating monster! Swoosh...! Buahhahhah!'\n";
 }
 load_chat(3, chat_str);
 set_log(1);
}
