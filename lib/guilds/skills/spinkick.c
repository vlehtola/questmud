get_time() { return 2+random(2); }
ep_cost() { return 3; }
query_type() { return "offensive"; }

fail_skill(arg) {
  object ob;
  int i;
  if(!arg) {
    write("Use spinkick at who?\n");
    return 1;
  }
  ob = present(arg, environment(this_player()));
  if(!ob || !living(ob)) {
    write(arg+" is not a valid target.\n");
    return 1;
  }
  write("You fail to hit "+ob->query_name()+" with your kick.\n");
  say(this_player()->query_name()+" tries to kick "+
    ob->query_name()+" with some spinning maneuver.\n",ob);
  tell_object(ob, this_player()->query_name()+
	" tries to give you a spinkick, but misses.\n");
}

resolve_skill(arg) {
  object ob;
  int i;
  if(!arg) {
    write("Use spinkick at who?\n");
    return 1;
  }
  ob = present(arg, environment(this_player()));
  if(!ob || !living(ob)) {
    write(arg+" is not a valid target.\n");
    return 1;
  }
  i = this_player()->query_skills("spinkick");
  i = i +(this_player()->query_dex() + this_player()->query_str());
  i = random(i) + i/2;
  if(i > 400) i = 400;
  if(i < 200) {
    write("You hit "+ob->query_name()+" with your spinkick.\n");
    say(this_player()->query_name()+" gives "+ob->query_name()+
	" a spinkick!\n",ob);
    tell_object(ob, this_player()->query_name()+" kicks you with "+
	"some spinning leg maneuver!\n");
  } else {
    write("Your nasty spinkick hits "+ob->query_name()+" right on the ribs.\n");
    say(this_player()->query_name()+" gives "+ob->query_name()+
	" a nasty spinkick on the ribs!\n",ob);
    tell_object(ob, this_player()->query_name()+" kicks your ribs with "+
	"some nasty spinning leg maneuver!\n");
  }
  ob->hit_with_spell(i);
  this_player()->attack_object(ob, 1);
}
