object liv;
int delay, images;

start(ob, effect, time) {
  liv = ob;
  delay = time;
  images = effect;
  shadow(liv, 1);
  call_out("mirror_out", delay);
}

hit_player(int dam,dam_type) {
  if (!dam) { liv->hit_player(dam,dam_type); return; }
  if(random(images+1) != 0) {
    images -= 1;
    tell_room(environment(liv),"An image vanishes.\n",({liv}));
    tell_object(liv, "One of your images vanish.\n");
    if (images < 1) {
	destruct(this_object());
    }
    return 0;
  }
  liv->hit_player(dam,dam_type);
}

hit_with_spell(int dam,dam_type) {

  if (!dam) { liv->hit_with_spell(dam,dam_type); return; }

  if(random(images+1) != 0) {
    images -= 1;
    write("An image vanishes.\n");
    tell_object(liv, "An image vanishes.\n");
    if (images < 1) {
	destruct(this_object());
    }
    return 0;
  }
  liv->hit_with_spell(dam,dam_type);
}

move_player(arg1,arg2,arg3,arg4,arg5,arg6,arg7) {
  liv->move_player(arg1,arg2,arg3,arg4,arg5,arg6,arg7);
  write("All your images vanish.\n");
  destruct(this_object());
}

short(mixed arg) {
  string much, normal;
  normal = liv->short(arg);
  if (arg) { return normal; }
  if(images == 0) {
    delay = 0;
    mirror_out();
    return;
  }
  images += 1;
  if (images == 1) { much = "one"; }
  if (images == 2) { much = "two"; }
  if (images == 3) { much = "three"; }
  if (images == 4) { much = "four"; }
  if (images == 5) { much = "five"; }
  if (images == 6) { much = "six"; }
  if (images == 7) { much = "seven"; }
  if (images == 8) { much = "eight"; }
  if (images == 9) { much = "nine"; }
  if (images == 10) { much = "ten"; }
  if (images > 10) { much = "many"; }
  images -= 1;
  if (!much) { return normal; }
  return capitalize(much) + " times " + normal;
}

query_mirror_image() {
  return images;
}

set_stunned() {
  tell_object(liv, "The mirrors prevent you from being stunned!\n");
  return 1;
}

mirror_out() {
    if(liv)tell_object(liv, "Your images slowly fade and vanish.\n");
    destruct(this_object());
    return 1;
}

void remove_one_mirror_image() {
  tell_room(environment(liv),"An image vanishes.\n",({liv}));
  tell_object(liv, "One of your images vanish.\n");
  images -= 1;
  if(images == 0) {
    mirror_out();
  }
}


