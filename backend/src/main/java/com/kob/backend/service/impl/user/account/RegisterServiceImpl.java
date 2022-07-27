package com.kob.backend.service.impl.user.account;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.kob.backend.mapper.UserMapper;
import com.kob.backend.pojo.User;
import com.kob.backend.service.user.account.RegisterService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Service
public class RegisterServiceImpl implements RegisterService {
    @Autowired
    private UserMapper userMapper;

    @Autowired
    private PasswordEncoder passwordEncoder;


    @Override
    public Map<String, String> register(String username, String password, String confirmedpassword) {


        Map<String, String> map = new HashMap<>();
        if (username == null) {
            map.put("error_message", "username can not be empty");
            return map;
        }
        if (password == null || confirmedpassword == null) {
            map.put("error_message", "password can not be empty");
            return map;
        }
        username = username.trim();
        if (username.length() == 0) {
            map.put("error_message", "username can not be empty");
            return map;
        }
        if (password.length() == 0 || confirmedpassword.length() == 0) {
            map.put("error_message", "password can not be empty");
            return map;
        }

        if (username.length() > 100) {
            map.put("error_message", "username length can not exceed 100");
            return map;
        }
        if (password.length() > 100 || confirmedpassword.length() > 100) {
            map.put("error_message", "password length can not exceed 100");
            return map;
        }
        if (!password.equals(confirmedpassword)) {
            map.put("error_message", "two passwords are not match");
            return map;
        }
        QueryWrapper<User> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("username", username);
        List<User> users = userMapper.selectList(queryWrapper);
        if (!users.isEmpty()) {
            map.put("error_message", "username is already exist");
            return map;
        }

        String encodedPassword = passwordEncoder.encode(password);
        String photo = "https://pbs.twimg.com/media/Eu4cWIkVoAAEsEz.jpg";
        User user = new User(null, username, encodedPassword, photo);
        userMapper.insert(user);

        map.put("error_message", "success");

        return map;
    }
}
