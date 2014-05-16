
asciiList = File.open('ascii')
outfile = File.open("asciiout.txt", 'w')

charOffset = 0

asciiList.each_line do |line|
	data =line.gsub(/\s+/m, ' ').strip.split(" ")
	asciiIdx=data[0]
	character=data[1]
	length=(data[2].to_i) * 2
	thisOut = "\nbyte " + asciiIdx + "_base[] PROGMEM = { //" + character + "\n"

	asciiLineFile =File.open('asciiin.txt')
	asciiLineFile.each_line do |arrayLine|
		asciiLine = arrayLine[charOffset, length] + "\n"
		asciiBinary = asciiLine.gsub(/\,/,"").to_i(2)
		#sprintf adds leading 0 to indicate octal, then convert the number to octal
		thisOut += sprintf("0%03o", asciiBinary) + ",\t//" + asciiLine
	end
	asciiLineFile.close

	thisOut += "}\n"

	outfile.write(thisOut)
	charOffset += length
end

asciiList.close