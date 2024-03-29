# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generator.pl                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 16:18:28 by llaurent          #+#    #+#              #
#    Updated: 2019/08/19 16:18:46 by llaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/perl
use warnings;
use strict;
die "program x y density [void, obs, full]" unless (scalar(@ARGV) == 6 || scalar(@ARGV) == 3);
if (scalar(@ARGV) == 3)
{
	my ($x, $y, $density) = @ARGV;
	print "$y.ox\n";
		for (my $i = 0; $i < $y; $i++) {
  		  for (my $j = 0; $j < $x; $j++) {
   	        if (int(rand($y) * 2) < $density) 
			   {
					print "o";
   	    	    }
   	        else 
			   {
					print "."; }
   		        }
		print "\n"; 
	}
}
else
{
	my ($x, $y, $density, $void, $obs, $full) = @ARGV;
	print "$y$void$obs$full\n";
		for (my $i = 0; $i < $y; $i++) {
  		  for (my $j = 0; $j < $x; $j++) {
   	        if (int(rand($y) * 2) < $density) 
			   {
					print "$obs";
   		        }
   	        else 
			   {
					print "$void"; }
   		        }
		print "\n"; 
	}
}

