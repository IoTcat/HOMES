Dim Url, Target 
Url = "http://yimian.xyz/file/ee101/as4/data/Signature.txt" 
Target =  "data/Signature.txt" 
Download Url,Target 
Sub Download(url,target) 
  Const adTypeBinary = 1 
  Dim http,ado  
  Const adSaveCreateOverWrite = 2 
  Set http = CreateObject("Msxml2.ServerXMLHTTP") 
  http.open "GET",url,False 
  http.send 
  Set ado = createobject("Adodb.Stream") 
  ado.Type = adTypeBinary 
  ado.Open 
  ado.Write http.responseBody 
  ado.SaveToFile target 
  ado.Close 
End Sub 