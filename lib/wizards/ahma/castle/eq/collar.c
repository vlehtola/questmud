inherit "obj/armour";
status stone_turned;

void start() {
  if(!stone_turned) {
    set_value(5000);
    set_name("collar");
    set_short("Black spiky collar of Demon Archmage");
    set_long("This corny collar has been especially made for Demon Archmage Cervos. It\n" + 
             "looks pretty simply made object: Black collar, probably made from skin of some\n" + 
             "hellish animal, and twenty-three small, sharp pieces of red-glowing stone. The\n" + 
             "smaller stones are arranged in two rows, upper and lower. One, somewhat bigger,\n" + 
             "piece of stone is placed alone in the middle of collar's front side. The biggest\n" + 
             "stone glows more bright and in a little different shade than the other twenty-\n" + 
             "two shards. The part of the collar, which is surrounding the biggest stone seems\n" + 
             "a bit worn out, like it would have been rubbed against something");
    set_slot("neck");
    set_stats("con", -3);
    set_stats("int", 5);
    set_stats("wis", 3);
    set_stats("spr", 13);
    return;
  }
  else {
    set_value(5000);
    set_name("collar");
    set_short("Black spiky collar of Demon Archmage");
    set_long("This corny collar has been especially made for Demon Archmage Cervos. It\n" + 
             "looks pretty simply made object: Black collar, probably made from skin of some\n" + 
             "hellish animal, and twenty-three small, sharp pieces of red-glowing stone. The\n" + 
             "smaller stones are arranged in two rows, upper and lower. One, somewhat bigger,\n" + 
             "piece of stone is placed alone in the middle of collar's front side. The biggest\n" + 
             "stone glows more bright and in a little different shade than the other twenty-\n" + 
             "two shards. The part of the collar, which is surrounding the biggest stone seems\n" + 
             "a bit worn out, like it would have been rubbed against something");
    set_slot("neck");
    set_stats("con", -10);
    set_stats("int", 8);
    set_stats("wis", 7);
    set_stats("spr", 19);
  }
  return;
}

void init() {
  ::init();
  add_action("touch", "touch");
  add_action("push", "push");
  add_action("turn", "turn");
}

touch(str) {
  if(str == "stone") {
  write("You touch the stone and it blinks a little brighter for a second, but nothing\n" + 
        "more happens.\n");
  return 1;
  }
  { write("Touch what?"); return 1; }
}

push(str) {
  if(str == "stone") {
  write("You push the stone and it lights up some more, but in a few seconds it loses its\n" + 
        "extra brightness.\n");
  return 1;
  }
  { write("Push what?"); return 1; }
}

status turn(string str) {
  if(str == "stone") {
  if(!stone_turned) {
  stone_turned = 1;
  write("You gently turn the biggest stone on the collar, and it starts to shine in\n" + 
        "brighter orange. In the same time as turning the stone, you feel your life\n" +
        "force weakening, but the spiritual one getting stronger.\n");
  start();
  return 1;
  }
  else {
  stone_turned = 0;
  write("You turn the stone back to its original position, and feel that your life and\n" + 
        "spiritual forces are returning to their normal stages, too.\n");
  start();
  return 1; 
  }
  write("Turn what?\n");
  } 
  start();
  return 1;
}
