get_time(str) {
  return random(1)+4;
}
ep_cost() { return 2; }
query_type() { return "neutral"; }

resolve_skill(str) {
   object poison,target;
   if(!str) {
           write("use cure poison at whom?\n");
           return 1;
   }
    target = present(str, environment(this_player()));
    if(!target || !living(target)) {
    write(capitalize(str)+" is not a valid target.\n");
    return 1;
}
    write(target->query_name()+" is cured from the poison.\n");
    tell_object(target, "You are cured from the poison!\n");
    target->end_poison();
}

fail_skill(str) {
        write("fail\n");
}
