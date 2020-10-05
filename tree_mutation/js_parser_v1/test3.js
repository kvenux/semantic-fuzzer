function Animal(name, height)
{
  this.name = name
  this.canWalk = true
  if (name == "bird")
  {
    this.canFly = true;
  }
}
var animal = new Animal("animal");
var bird = new Animal("bird");
assert(animal.canWalk === true);
assert(bird.canWalk === true);
assert(animal.canFly === undefined);
assert(bird.canFly === true);