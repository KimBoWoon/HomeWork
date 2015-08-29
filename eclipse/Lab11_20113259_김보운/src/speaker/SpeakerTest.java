package speaker;

public class SpeakerTest 
{
	public static void main(String[] args)
	{
		Speaker guest = new Philosopher("thinking");
		guest.speak();
		guest = new Dog();
		guest.speak();
	}
}
