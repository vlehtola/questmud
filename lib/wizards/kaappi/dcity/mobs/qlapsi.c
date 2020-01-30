inherit "obj/monster";
string chat_str;

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(5+random(5));
  set_name("dalia");
  set_race("dwarf");
  set_alias("child");
  set_gender(2);
  set_short("Dalia, a little child");
  set_long("This child is very young. She is\n"+
           "sitting under the tree, and she looks\n"+
           "very sad. Her eyes are red and in her\n"+
           "dirty faces can be seen some stripes\n"+
           "which are made by her tears.\n");
  set_al(40);

  set_aggressive(0);

if (!chat_str) {
   chat_str = allocate(2);
   chat_str[0] = "Dalia sobs: 'Please, bring Boltak's doll back...'\n";
   chat_str[1] = "Dalia sobs: 'He is my brother and he is totally unbearable now as he has lost his doll.'\n";
}
load_chat(2, chat_str);
}
