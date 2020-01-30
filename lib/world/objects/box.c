#define TUNE_FACTOR 8

int money,type,locked,short_desc,open, hits, max_hits;

query_no_save() { return 1; }

activate_trap() {
  int i;
  object ob;
  i = random(3);
  if(i==0) {
    tell_room(environment(this_object()), "The box explodes!\n");
    ob = all_inventory(environment(this_object()));
    while(i<sizeof(ob)) {
      ob[i]->hit_with_spell(200*(1+type), "fire");
      i += 1;
    }
    destruct(this_object());
    return 1;
  }
  if(i==1) {
    tell_room(environment(this_object()), "A violent blast of venom shoots out from the box as it opens!\n");
    i=0;
    ob = all_inventory(environment(this_player() ));
    while(i<sizeof(ob)) {
      if(living(ob[i])) ob[i]->hit_with_spell((random(6)+3)*100, "poison");
      i += 1;
    }
    force_unlock();
    return 1;
  }
  if(i==2) {
    tell_room(environment(this_object()), "You hear a clicking sound from the box.\n");
    return 1;
  }

}
force_unlock() {
  say("The box unlocks!\n");
  locked = 0;
}

query_weight() { return (type+1)*200; }
query_long() { return "A box that is used to store money. It can be forced open, if the key is missing. It might be trapped though.\n"; }

long() {
  write(short()+"\n");
  write("A box that is used to store money. It can be forced open,\n"+
        "if the key is missing. It might be trapped, though.\n");
  if(locked) {
    write("It is locked.\n");
    return 1;
  }
  if(!open) {
    write("It is closed.\n");
    return 1;
  }
  if (!first_inventory(this_object())) {
        write("It is empty.\n");
        return 1;
  }
  write("It contains: "+first_inventory(this_object())->short()+"\n");
  return 1;
}
force(str) {
  int i;
  object ob;
  string tmp;
  if (!str) { return 0; }
  if(this_object() != present(str,environment(this_object()))) return 0;
  if(sscanf(file_name(environment(this_object())), "world/arena/%s", tmp) == 1) {
    write("You cannot open the box here.\n");
    return 1;
  }
  if(environment(this_object()) != environment(this_player() )) {
    write("The box must be put on ground before it can be forced.\n");
    return 1;
  }
  if(!locked) {
    write("The box is already unlocked.\n");
    return 1;
  }
  ob = this_player()->query_right_weapon();
  if(!ob) { write("You need a weapon to do this.\n"); return 1; }

//You can't force a box with knuckles
  if(ob->query_type() == "knuckles") {
        write("You hit the box painfully with your hand!\n");
        say(this_player()->query_name()+" tries to force the box but only hurts "+
        this_player()->query_possessive()+" hand.\n");
        this_player()->hit_with_spell(random(300),"physical");
        write("It doesn't seem to take any damage.\n");
        return 1;
  }

  i = this_player()->query_str()/20+2;
  hits -= i;
  if(random(10) < type) {
    write("You smash "+short()+" with all your might! ..and your "+ob->short()+" breaks.\n");
    say(this_player()->query_name()+" smashes "+short()+", but just breaks "+
        this_player()->query_possessive()+" "+ob->short()+".\n",this_player());
    hits -= i*2;
    //No instant breaks -- Rag 7.7.2004
    ob->set_dur(ob->query_dur()-random(10)-10,1);
    ob->check_weapon_break();
    /*this_player()->unwield(ob);
    destruct(ob);*/
    return 1;
  }
  if(hits > 0) {
    write("You hit the lock with your "+ob->short()+", but don't manage to break it.\n");
    say(this_player()->query_name()+" hits the lock with "+this_player()->query_possessive()+
        " "+ob->short()+", but doesn't manage to break it.\n");
    if(!random(10)) activate_trap();
    return 1;
  }
  write("You manage to break the lock of "+short()+"!\n");
  say(this_player()->query_name()+" manages to break the lock of "+short()+"!\n",this_player());
  locked = 0;
  return 1;
}

id(str) { return str == "box"; }
reset(arg) {
  int i;
  if(arg) return;
  locked = 1;
  i = random(15)+1;
  set_short("A wooden box");
  if(i>=6) set_short("A wooden, iron reinforced box");
  if(i>=10) set_short("An iron box");
  if(i>=13) set_short("An iron, steel reinforced box");
  if(i==15) set_short("A hard steel box");
  hits = i*i*2;
  max_hits = hits;
  type = i/3;
  if(type < 1) type = 1;
  money = (random(4000) + 5000 + i * 500)*TUNE_FACTOR;
  i = 1;
  while(i < type) {
     money = money / 10;
     i += 1;
  }
}

short() {
  string tmp, op;
  op = "";
  if (open) op = " (open)";
  if(hits < max_hits) tmp = "(lightly bruised)";
  if(hits < max_hits*3/4) tmp = "(somewhat bruised)";
  if(hits < max_hits/2) tmp = "(bruised)";
  if(hits < max_hits/4) tmp = "(heavily bruised)";
  if(hits < max_hits/8) tmp = "(barely intact)";
  if(tmp) return short_desc+" "+tmp+op;
  return short_desc+op;
}
set_short(str) { short_desc = str; }
init() {
  add_action("open", "open");
  add_action("force", "force");
}
can_put_and_get() { return open; }
get() { return 1; }
open(str) {
  object ob;
  if (!str) { write("Open what?\n"); return 1; }
  if(this_object() != present(str,environment(this_object()))) return;
  if(locked>0) {
    write("The box is locked. You can try to force it open, but might lose your weapon.\n");
    return 1;
  }
  if (open) { write("The box is already open.\n"); return 1; }
  write("You open the box.\n");
  ob = clone_object("/obj/new_money");
  ob->set_value(money);
  ob->set_type(type);
  move_object(ob,this_object());
  open = 1;
  log_file("BOX_OPENED", ctime(time())+"; "+
    short()+" with "+money+" "+
    call_other("/obj/new_money","query_type_string", type)+" coins opened by "+
    this_player()->query_name()+".\n");
  return 1;
}
