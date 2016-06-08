// Name: Emmett Casey

import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class Assignment4A
{
	
	public int minPrice(String[] tiles)
	{
		int [] minCost = new int [tiles.length * 3];
		for (int i = 0; i < minCost.length; i += 3)
		{
			String [] inputSplit = tiles[i / 3].split(" ");
			for (int j = 0; j < 3; j++)
				minCost[i + j] = new Integer(inputSplit[j]);
		}

		for (int i = 3; i < minCost.length; i++)
		{
			int indexSameColorPrevious = i % 3;
			if (indexSameColorPrevious == 0)
				minCost[i] += Math.min(minCost[i - 1], minCost[i - 2]);
			else if (indexSameColorPrevious == 1)
				minCost[i] += Math.min(minCost[i - 2], minCost[i - 4]);
			else
				minCost[i] += Math.min(minCost[i - 5], minCost[i - 4]);	
		}

		int size = minCost.length;
		int answer = Math.min(minCost[--size], minCost[--size]);
		answer = Math.min(answer, minCost[--size]);
		return answer;
	}
}