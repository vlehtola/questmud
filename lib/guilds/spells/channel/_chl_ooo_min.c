/* call angel // Celtron */

#define ANGEL "/guilds/spell_obj/angel"

resolve(int bonus, string target, object caster_ob) {
  object angel, room;
  room = environment(caster_ob);
  if(room->query_not_out()) {
    write("You cannot complete your chant indoors.\n");
    return 1;
  }

  angel = clone_object(ANGEL);
  angel->start_angel(caster_ob, 1);
  move_object(angel, room);
  tell_room(room, angel->short()+" descends from the sky.\n");
  return 1;
}
