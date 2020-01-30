get_time() {
    return 7;
}

ep_cost() {
  return 10;
}
query_type() { return "neutral"; }

resolve_skill(target, object who) {
object ob;
if(!target) {
write("Use at what?\n");
return 1;
}
ob = present(target, environment(this_player()));
if(!ob) {
write("No such thing here.\n");
return 1;
}
if(!living(ob) || ob == this_player() || ob->query_npc()) {
write(target+" is not a valid target.\n");
return 1;
}
write("You try to tempt the "+target+" to more evil.\n");
if(ob->query_alignment() > 50) {
write("The target is too pure hearted to this skill work.\n");
return 1;
}
write("You turn the mind of "+target+" to evil.\n");
ob->add_alignment(-10);
tell_object(ob, this_player()->query_name()+" tries to turn your mind to be more evil.\n");
return 1;
}

fail_skill(target) {
    write("You fail the skill.\n");
    say(capitalize(this_player()->query_name()) + " fails the skill.\n");
    return 1;
}
