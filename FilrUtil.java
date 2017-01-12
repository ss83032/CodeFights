    public static String writeFile(String file, String s) {
        if (!isExist(file)) {
            Debug.LogE(TITLE, file + " is not exist");
            return null;
        }
        FileWriter fstream = null;
        try {
            fstream = new FileWriter(file);
            fstream.write(s);
            fstream.flush();
            fstream.close();
            fstream = null;
        } catch (Exception e) {
            if (Const.DBG)
                Debug.LogE(TITLE, "Write File fail(" + file + ")");
            e.printStackTrace();
        } finally {
            if (fstream != null) {
                try {
                    fstream.close();
                } catch (java.io.IOException e) {
                    e.printStackTrace();
                }
            }
        }

        return null;
    }

    public static String readFile(String filePath) {
        try {
            return getStringFromFile(filePath);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    public static String getStringFromFile(String filePath) throws Exception {
        String ret = "";
        try {
            File fp = new File(filePath);
            if (!fp.exists()) {
                // Debug.LogE(TITLE, filePath + " is not exist !");
                return ret;
            }
            FileInputStream fin = new FileInputStream(fp);
            Scanner scanner = new Scanner(fin).useDelimiter("\\A");
            ret = fastConvertStreamToString(scanner);
            // Make sure you close all streams.
            fin.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return ret;
    }
