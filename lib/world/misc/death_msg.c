get_msg(mixed hit) {
  object ob;
  int i;
  ob = previous_object();
  if(intp(hit)) {
    hit = call_other("/obj/resists", "resist_names", hit);
  }
  /* normaali iskuihin kuolleet */
  i = random(10); /* aina ei tarvii tulla messua */
  if(hit == "physical") {
   if(i == 0)
    return ob->query_name()+"'s torso is cut in two!";
   if(i == 1)
    return ob->query_name()+"'s mutilated body falls down.. lifeless.";
   if(i == 2)
    return ob->query_name()+" draws "+ob->query_possessive()+" last breath and falls.";
   if(i == 3)
    return "The room is covered with brain tissue, as "+ob->query_name()+"'s head splits.";
   if(i == 4)
    return ob->query_name()+" staggers from the blow, falls down and dies.";
   if(i == 5)
    return ob->query_name()+" stares at you, horrified, as "+ob->query_possessive()+" entrails fall out.";
   if(i == 6)
    return ob->query_name()+" tries to move, but collapses in "+ob->query_possessive()+" mortal wounds.";
  }
  if(hit == "fire") {
   if(i == 0)
    return ob->query_name()+"'s flaming body falls down.. lifeless.";
   if(i == 1)
    return ob->query_name()+"'s head is burn away!";
   if(i == 2)
    return ob->query_name()+" screams as "+ob->query_possessive()+" face melts!";
   if(i == 3)
    return "The fire burns "+ob->query_name()+" and leaves nothing, but a charred body.";
  }
  if(hit == "cold") {
   if(i == 0)
    return ob->query_name()+" looks horrified as "+ob->query_possessive()+" face freezes!";
  }
}
