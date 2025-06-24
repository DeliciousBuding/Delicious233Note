Set argv = WScript.Arguments
if argv.Count < 1 then
WScript.Quit
end if
Set pptApp = CreateObject("PowerPoint.Application")
For Each argv In WScript.Arguments
filename = argv
if right(filename, 3) = "ppt" or right(filename, 3) = "pps" then
pdfname = left(filename, len(filename)-3) + "pdf"
elseif right(filename, 4) = "pptx" then
pdfname = left(filename, len(filename)-4) + "pdf"
else
msgbox(filename+" is not ppt/pptx!")
WScript.Quit
end if
Set MyPress = pptApp.Presentations.Open(filename)
ppSaveAsPDF = 32
MyPress.SaveAs pdfname, ppSaveAsPDF, false
MyPress.Close
Next
pptApp.Quit