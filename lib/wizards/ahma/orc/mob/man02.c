inherit "obj/monster";
int i;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+21+(i*3));
  set_name("man");
  set_race("orc");
  set_gender(1);
  if (!i) { set_short("An Orcish man is leaning against a wall here"); } else { set_short("A strong and smart-looking Orcish man"); }
  set_long("A common-looking Orcish man is leaning against the wooden wall in here.\n" + 
           "He seems to be the head of this house, which can be concluded from his\n" + 
           "reserved observation against uninvited visitors, like you. The man is\n" + 
           "wearing a common set of Orcish clothes: A shirt and shorts. Man seems\n" + 
           "to be willing to protect his house from invaders.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Man eyes at you suspiciously.\n";
    chat_str[1] = "Man quickly scrathes his nose.\n";
    chat_str[2] = "Man coughs into his fist to gain attention.\n";
  }
  load_chat(3, chat_str);
  if(!present("shirt", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/greenshirt"), this_object()); init_command("wear shirt"); }
  if(!present("shorts", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/shorts"), this_object()); init_command("wear shorts"); }
}

specname() {
  i = 1;
  reset();
}    