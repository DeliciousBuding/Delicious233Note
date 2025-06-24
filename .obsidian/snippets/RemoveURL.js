const removeReferenceLinks = async () => {
    const clipboardText = await navigator.clipboard.readText();
    const cleanText = clipboardText.replace(/(\[¶\]|\])\(https?:\/\/[^\)]+\)/g, '');
    await navigator.clipboard.writeText(cleanText);
};