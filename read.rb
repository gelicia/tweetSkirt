
asciiList = File.open('ascii')
outfile = File.open("asciiout.txt", 'w')

lengthArray = []
charOffset = 0

outfile.write("byte all[] PROGMEM = {\n")

asciiList.each_line do |line|
	data =line.gsub(/\s+/m, ' ').strip.split(" ")
	asciiIdx=data[0]
	character=data[1]
	length=(data[2].to_i) * 2
	thisOut = "//" + character + "\n"

	asciiLineFile =File.open('asciiin.txt')
	asciiLineFile.each_line do |arrayLine|
		asciiLine = arrayLine[charOffset, length] + "\n"
		asciiBinary = asciiLine.gsub(/\,/,"").to_i(2)
		#sprintf adds leading 0 to indicate octal, then convert the number to octal
		thisOut += sprintf("0%03o", asciiBinary) + ",\t//" + asciiLine
	end
	asciiLineFile.close

	thisOut += "\n"

	outfile.write(thisOut)
	lengthArray.push(length/2)
	charOffset += length
end

asciiList.close
outfile.write("} \nint lengths[] = {" + lengthArray.join(",") + "}")
outfile.close