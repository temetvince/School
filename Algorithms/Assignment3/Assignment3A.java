// Name: Emmett Casey

import java.util.*;

public class Assignment3A
{
	public int numPaint(String input)
	{
		ArrayList<Integer> cost = new ArrayList<Integer>();
		int [] bsAtAfterLocation = new int [input.length()];
		int bs = 0;
		for (int i = input.length() - 1; i >= 0; i--)
		{
			if (input.charAt(i) == 'B')
				bsAtAfterLocation[i] = ++bs;
			else
				bsAtAfterLocation[i] = bs;
		}
		for (int i = 0; i < input.length(); i++)
			cost.add(runAlg(0, 0, input, cost, bsAtAfterLocation));
		int min = cost.get(0);
		for (int i = 1; i < cost.size(); i++)
			if (cost.get(i) < min)
				min = cost.get(i);
		return min;
	}

	private int runAlg(int prevCost, int prevI, String input, ArrayList<Integer> cost, int [] bsAtAfterLocation)
	{
		int i = 0;
		while (input.charAt(i) != 'W' && i != input.length() - 1)
			i++;
		if (i == input.length() - 1)
			return prevCost;
		cost.add(bsAtAfterLocation[i + prevI] + prevCost);
		return runAlg(++prevCost, prevI + i + 1, input.substring(i + 1), cost, bsAtAfterLocation);
	}
}